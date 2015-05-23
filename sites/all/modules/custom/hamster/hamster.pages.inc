<?php

define('HAMSTER_ITEMS_PER_PAGE', 5);
/**
 * Hamster view page.
 */
function hamster_page($hamster) {
  return theme('hamster_info', array('hamster' => $hamster));
}

/**
 * Title callback for hamster view page.
 */
function hamster_page_title($hamster) {
  return $hamster->name;
}


/**
 * Page callback that lists all hamsters in the database.
 */
function hamster_list() {
  $output = '';
  
  // Avoid including all the data from each row as a DB query optimization.
  $total = db_query("SELECT COUNT(h.id) FROM {hamster} AS h")->fetchField();
  $page = pager_default_initialize($total, HAMSTER_ITEMS_PER_PAGE);
  
  $results = db_query_range("SELECT h.*, hh.name AS habitat_name FROM {hamster} h
                             LEFT JOIN {hamster_habitat} hh ON h.habitat_id = hh.id", 
                             $page * HAMSTER_ITEMS_PER_PAGE, 
                             HAMSTER_ITEMS_PER_PAGE);
  
  $rows = array();
  foreach ($results as $record) {
    $image = file_load($record->image);
    if (!empty($image)) {
      $image_thumbnail = theme('image_style', array('style_name' => 'thumbnail', 'path' => $image->uri));
    }
    else {
      $image_thumbnail = '';
    }
    
    // The destination query parameter works on *every* Drupal form system wide.
    // Instead of return back to the same page, the page will be automatically
    // be redirected to the value of the destination parameter.
    $link_query = array('destination' => 'hamster');
    if (!empty($_GET['page'])) {
      // Because this ia a variable inside of a variable, this needs to include
      // the ? character instead of an ampersand.
      $link_query['destination'] .= '?page=' . $_GET['page'];
    }
    
    $row = array(
      $record->id,
      l($record->name, 'hamster/' . $record->id),
      $record->gender,
      t('@weight g', array('@weight' => $record->weight)),
      format_date($record->birthdate, 'custom', 'Y-m-d'),
      $image_thumbnail,
      $record->habitat_name,
      l('View', 'hamster/' . $record->id) . ' - ' .
      l('Edit', 'hamster/' . $record->id . '/edit', array('query' => $link_query)) . ' - ' .
      l('Delete', 'hamster/' . $record->id . '/delete', array('query' => $link_query)),
    );
    
    $rows[] = $row;
  }
  
  $header = array(
    t('ID'),
    t('Name'),
    t('Gender'),
    t('Weight'),
    t('Birth Date'),
    t('Image'),
    t('Habitat'),
    t('Actions'),
  );
  
  $variables = array(
    'rows' => $rows,
    'header' => $header,
  );
  
  $output .= theme('table', $variables);
  $output .= theme('pager');
  
  return $output;
}

/**
 * Hamster add/edit form.
 */
function hamster_edit_form($form, &$form_state, $hamster = NULL) {
  
  $form['id'] = array(
    '#type' => 'value',
    '#value' => isset($hamster->id) ? $hamster->id : NULL,
  );
  
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => isset($hamster->name) ? $hamster->name : NULL,
    '#required' => TRUE,
  );
  
  $form['gender'] = array(
    '#type' => 'radios',
    '#title' => t('Gender'),
    '#options' => array('male' => t('Macho Man'), 'female' => t('Girlie Girl')),
    '#default_value' => isset($hamster->gender) ? $hamster->gender : NULL,
  );
  
  $form['weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Weight'),
    '#field_suffix' => 'grams',
    '#size' => 5,
    '#default_value' => isset($hamster->weight) ? $hamster->weight : NULL,
  );
  
  // birthdate is a Unix timestamp number.
  if (isset($hamster->birthdate)) {
    $birthdate_default = array(
      'year' => date('Y', $hamster->birthdate),
      // Month without leading zeroes.
      'month' => date('n', $hamster->birthdate),
      // Day without leading zeroes.
      'day' => date('j', $hamster->birthdate),
    );
  }
  $form['birthdate'] = array(
    '#type' => 'date',
    '#title' => t('Birth Date'),
    '#default_value' => isset($birthdate_default) ? $birthdate_default : NULL,
  );
  
  $form['image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image'),
    '#upload_location' => 'public://hamster-images/',
    '#default_value' => isset($hamster->image) ? $hamster->image : NULL,
  );
  
  // fetchAllKeyed returns all of the results in the form of an array.
  // $key_index defaults to 0. $value_index defaults to 1.
  // $habitats = db_query("SELECT id, name FROM {hamster_habitat}")->fetchAllKeyed(0, 1);
  $habitats = db_query("SELECT id, name FROM {hamster_habitat}")->fetchAllKeyed();
  
// The addition operand is overloaded to include unioning of associative arrays.
  $habitats = array('' => '--Select a Habitat--') + $habitats;
  
  $form['habitat_id'] = array(
    '#type' => 'select',
    '#title' => t('Habitat'),
    '#options' => $habitats,
    '#default_value' => isset($hamster->habitat_id) ? $hamster->habitat_id : NULL,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Hamster'),
  );
  
  return $form;
}

/**
 * Submit handler for hamster add/edit form.
 */
function hamster_edit_form_submit($form, &$form_state) {
  // Because the form names were chosen to use the same names as in the database
  // the updates required are trivial.
  
  $hamster = $form_state['values'];
  // dpm($hamster);
  
  $hamster['birthdate'] = strtotime($hamster['birthdate']['year'] . '-' 
                                    . $hamster['birthdate']['month'] . '-' 
                                    . $hamster['birthdate']['day']);
  // dpm($hamster);
  
  if (!empty($hamster['id'])) {
    // Existing hamster. Need to tell drupal_write_recorder() which the primary
    // key is.
    $result = drupal_write_record('hamster', $hamster, array('id'));
    drupal_set_message(t('Hamster %name updated: @result', array('%name' => $hamster['name'], '@result' => $result)));
  }
  else {
    // New hamster. As a side effect, drupal_write_record will add 'id' to the
    // input array which in this case is $hamster.
    $result = drupal_write_record('hamster', $hamster);
    drupal_set_message(t('Hamster %name created: @result.', array('%name' => $hamster['name'], '@result' => $result)));
  }
  
  // Updated content. Must tell the cache to clear.
  cache_clear_all('perf_demo:hamsters:list', 'cache');
  
  if (!empty($hamster['image'])) {
    $file = file_load($hamster['image']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    
    $file_usage = file_usage_list($file);
    if (empty($file_usage['hamster']['hamster'][$hamster['id']])) {
      file_usage_add($file, 'hamster', 'hamster', $hamster['id']);
    }
  }
  else {
    hamster_delete_image($hamster['id']);
  }
  
  $form_state['redirect'] = 'hamster/' . $hamster['id'];
}

function hamster_delete_image($hamster_id) {
  // Was there a file assocaited with this hamster before?
  $fid = db_query('SELECT fid FROM {file_usage} WHERE module = :module AND type = :type and id = :id',
    array(':module' => 'hamster', ':type' => 'hamster', ':id' => $hamster_id))->fetchField();

  if (!empty($fid)) {
    // If so, clean up file.
    $file = file_load($fid);

    // Remove any hamster references to this image file.
    file_usage_delete($file, 'hamster');

    // file_delete() is smart. If another module is still using to\his image,
    // the managed file will not be removed until all references are gone.
    file_delete($file);
  }
 }

/**
 * Hamster delete form.
 */
function hamster_delete_form($form, &$form_state, $hamster) {
  $form['id'] = array(
    '#type' => 'value',
    '#value' => $hamster->id,
  );
  $form['name'] = array(
    '#type' => 'value',
    '#value' => $hamster->name,
  );
  return confirm_form($form, 
                      t('Are you sure you want to delete hamster %name?', 
                      array('%name' => $hamster->name)), 
                      'hamster/' . $hamster->id);
}

/**
 * Hamster delete submit form.
 */
function hamster_delete_form_submit($form, &$form_state) {
  $hamster_id = $form_state['values']['id'];
  
  hamster_delete_image($hamster_id);
 
  db_query("DELETE FROM {hamster} WHERE id = :id", 
            array(':id' => $hamster_id));
  drupal_set_message(t('Hamster %name deleted.', 
                      array('%name' => $form_state['values']['name'])));
  
  cache_clear_all('perf_demo:hamsters:list', 'cache');
  
  $form_state['redirect'] = 'hamster';
}

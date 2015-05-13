<?php

/**
 * @file
 * Definition of hamster_views_handler_field_image.
 */

/**
 * Field handler to provide simple renderer that allows using a themed user list.
 */

// By implementing, hook_views_data_alter() one can override the display of any
// views data. Tends to override every view of the site if not careful.

/**
 *
 * @ingroup views_field_handlers
 */
class hamster_views_handler_field_image extends views_handler_field {
  
  // Needed for updating UI.
  function option_definition() {
    $options = parent::option_definition();
    $options['image_style'] = array('default' => '');
    return $options;
  }
  
  // Als needed for updating UI.
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    if (module_exists('image')) {
      $styles = image_styles();
      $style_options = array('' => t('Full Size'));
      foreach ($styles as $style) {
        $style_options[$style['name']] = $style['name'];
      }

      $form['image_style'] = array(
        '#title' => t('Image style'),
        '#description' => t('Choose an image style for the hamster images.'),
        '#type' => 'select',
        '#options' => $style_options,
        '#default_value' => $this->options['image_style'],
      );
    }
  }
  
  // Minimal override.
  function render($values) {
    $output = '';
    $image_fid = $this->get_value($values);
    if ($image = file_load($image_fid)) {
      if ($this->options['image_style'] && module_exists('image')) {  
        $output = theme('image_style', 
                        array(
                          'style_name' => $this->options['image_style'], 
                          'path' => $image->uri,
                        )
        );
      }
      else {
        $output = theme('image', 
                        array(
                          'path' => $image->uri,
                        )
        );
      }
    }
    
    return $output;
  }
  
}


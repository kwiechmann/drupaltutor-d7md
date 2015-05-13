<?php

function hamster_views_data() {
  $data = array();

  $data['hamster']['table'] = array(
    'group' => t("Hamster"),
    'title' => t('Hamster Information'),
    'help' => t('List information about hamsters.'),
  );
  
  $data['hamster']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Hamsters'),
    'help' => t('Information about hamsters.'),
  );
  
  $data['hamster']['id'] = array(
    'title' => t('ID'),
    'help' => t('The ID of the hamster.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['hamster']['name'] = array(
    'title' => t('Name'),
    'help' => t('The name of the hamster'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['hamster']['gender'] = array(
    'title' => t('Gender'),
    'help' => t('The gender of the hamster'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'hamster_views_gender_options',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
    
  $data['hamster']['weight'] = array(
    'title' => t('Weight'),
    'help' => t('The weight of the hamster.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['hamster']['birthdate'] = array(
    'title' => t('Birth Date'),
    'help' => t('The birth date of the hamster.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  
  $data['hamster']['image'] = array(
    'title' => t('Image File ID'),
    'help' => t('The image file ID of the hamster.'),
    'field' => array(
      'handler' => 'hamster_views_handler_field_image',
    ),
    'relationship' => array(
      'label' => t('Image'),
      'base' => 'file_manage',
      'base field' => 'fid',
    ),
  );
  
  $data['hamster']['habitat_id'] = array(
    'title' => t('Habitat ID'),
    'help' => t('The habitat ID of the hamster.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'relationship' => array(
      'label' => t('Habitat'),
      'base' => 'hamster_habitat',
      'base field' => 'id',
    )
  );
  
  // Habitat Table
  // hamster_habitat will not be set up to make it a base table. This will 
  // prevent users making view of just the hamster habitat information
  $data['hamster_habitat']['table'] = array(
    'group' => t('Hamster Habitat'),
    'title' => t('Hamster Habitat Information'),
    'help' => t('List information about hamster cages.'),
  );
  
  $data['hamster_habitat']['id'] = array(
    'title' => t('ID'),
    'help' => t('The ID of the hamster habitat.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['hamster_habitat']['name'] = array(
    'title' => t('Name'),
    'help' => t('The name of the hamster habitat.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['hamster_habitat']['capacity'] = array(
    'title' => t('capacity'),
    'help' => t('The capacity of the hamster habitat.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

function hamster_views_gender_options() {
  // Override the default options of "Yes" and "No". "Any" is automatically 
  // included.
  return array(
    'male' => t('Macho Man'),
    'female' => t('Girlie Girl'),
  );
}

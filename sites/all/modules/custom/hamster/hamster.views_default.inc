<?php

function hamster_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'hamsters';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'hamster';
  $view->human_name = 'Hamsters';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hamsters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  /* Relationship: Hamster: Habitat ID */
  $handler->display->display_options['relationships']['habitat_id']['id'] = 'habitat_id';
  $handler->display->display_options['relationships']['habitat_id']['table'] = 'hamster';
  $handler->display->display_options['relationships']['habitat_id']['field'] = 'habitat_id';
  /* Field: Hamster: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'hamster';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Hamster: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'hamster';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'hamster/[id]';
  /* Field: Hamster: Gender */
  $handler->display->display_options['fields']['gender']['id'] = 'gender';
  $handler->display->display_options['fields']['gender']['table'] = 'hamster';
  $handler->display->display_options['fields']['gender']['field'] = 'gender';
  /* Field: Hamster: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'hamster';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['suffix'] = ' g';
  /* Field: Hamster: Birth Date */
  $handler->display->display_options['fields']['birthdate']['id'] = 'birthdate';
  $handler->display->display_options['fields']['birthdate']['table'] = 'hamster';
  $handler->display->display_options['fields']['birthdate']['field'] = 'birthdate';
  $handler->display->display_options['fields']['birthdate']['date_format'] = 'custom';
  $handler->display->display_options['fields']['birthdate']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['birthdate']['second_date_format'] = 'long';
  /* Field: Hamster: Image File ID */
  $handler->display->display_options['fields']['image']['id'] = 'image';
  $handler->display->display_options['fields']['image']['table'] = 'hamster';
  $handler->display->display_options['fields']['image']['field'] = 'image';
  $handler->display->display_options['fields']['image']['label'] = 'Image';
  $handler->display->display_options['fields']['image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['image']['image_style'] = 'thumbnail';
  /* Field: Hamster Habitat: capacity */
  $handler->display->display_options['fields']['capacity']['id'] = 'capacity';
  $handler->display->display_options['fields']['capacity']['table'] = 'hamster_habitat';
  $handler->display->display_options['fields']['capacity']['field'] = 'capacity';
  $handler->display->display_options['fields']['capacity']['relationship'] = 'habitat_id';
  $handler->display->display_options['fields']['capacity']['label'] = '';
  $handler->display->display_options['fields']['capacity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['capacity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['capacity']['separator'] = '';
  /* Field: Hamster Habitat: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'hamster_habitat';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'habitat_id';
  $handler->display->display_options['fields']['name_1']['label'] = 'Habitat (Capacity)';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '[name_1] ([capacity])';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'hamster/[id]?destination=hamster';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'hamster/[id]/delete?destination=hamster-view';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[nothing] - [nothing_1]';
  /* Sort criterion: Hamster: ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'hamster';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['id']['expose']['label'] = 'ID';
  /* Sort criterion: Hamster: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'hamster';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Name';
  /* Sort criterion: Hamster: Gender */
  $handler->display->display_options['sorts']['gender']['id'] = 'gender';
  $handler->display->display_options['sorts']['gender']['table'] = 'hamster';
  $handler->display->display_options['sorts']['gender']['field'] = 'gender';
  $handler->display->display_options['sorts']['gender']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['gender']['expose']['label'] = 'Gender';
  /* Sort criterion: Hamster: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'hamster';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Hamster: Birth Date */
  $handler->display->display_options['sorts']['birthdate']['id'] = 'birthdate';
  $handler->display->display_options['sorts']['birthdate']['table'] = 'hamster';
  $handler->display->display_options['sorts']['birthdate']['field'] = 'birthdate';
  $handler->display->display_options['sorts']['birthdate']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['birthdate']['expose']['label'] = 'Birth Date';
  $handler->display->display_options['sorts']['birthdate']['granularity'] = 'day';
  /* Sort criterion: Hamster Habitat: Name */
  $handler->display->display_options['sorts']['name_1']['id'] = 'name_1';
  $handler->display->display_options['sorts']['name_1']['table'] = 'hamster_habitat';
  $handler->display->display_options['sorts']['name_1']['field'] = 'name';
  $handler->display->display_options['sorts']['name_1']['relationship'] = 'habitat_id';
  $handler->display->display_options['sorts']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name_1']['expose']['label'] = 'Habitat';
  /* Filter criterion: Hamster: ID */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'hamster';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['group'] = 1;
  $handler->display->display_options['filters']['id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['identifier'] = 'id';
  $handler->display->display_options['filters']['id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hamster: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'hamster';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'word';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hamster: Gender */
  $handler->display->display_options['filters']['gender']['id'] = 'gender';
  $handler->display->display_options['filters']['gender']['table'] = 'hamster';
  $handler->display->display_options['filters']['gender']['field'] = 'gender';
  $handler->display->display_options['filters']['gender']['group'] = 1;
  $handler->display->display_options['filters']['gender']['exposed'] = TRUE;
  $handler->display->display_options['filters']['gender']['expose']['operator_id'] = 'gender_op';
  $handler->display->display_options['filters']['gender']['expose']['label'] = 'Gender';
  $handler->display->display_options['filters']['gender']['expose']['operator'] = 'gender_op';
  $handler->display->display_options['filters']['gender']['expose']['identifier'] = 'gender';
  $handler->display->display_options['filters']['gender']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hamster: Weight */
  $handler->display->display_options['filters']['weight']['id'] = 'weight';
  $handler->display->display_options['filters']['weight']['table'] = 'hamster';
  $handler->display->display_options['filters']['weight']['field'] = 'weight';
  $handler->display->display_options['filters']['weight']['group'] = 1;
  $handler->display->display_options['filters']['weight']['exposed'] = TRUE;
  $handler->display->display_options['filters']['weight']['expose']['operator_id'] = 'weight_op';
  $handler->display->display_options['filters']['weight']['expose']['label'] = 'Weight';
  $handler->display->display_options['filters']['weight']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['weight']['expose']['operator'] = 'weight_op';
  $handler->display->display_options['filters']['weight']['expose']['identifier'] = 'weight';
  $handler->display->display_options['filters']['weight']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hamster: Birth Date */
  $handler->display->display_options['filters']['birthdate']['id'] = 'birthdate';
  $handler->display->display_options['filters']['birthdate']['table'] = 'hamster';
  $handler->display->display_options['filters']['birthdate']['field'] = 'birthdate';
  $handler->display->display_options['filters']['birthdate']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['birthdate']['group'] = 1;
  $handler->display->display_options['filters']['birthdate']['exposed'] = TRUE;
  $handler->display->display_options['filters']['birthdate']['expose']['operator_id'] = 'birthdate_op';
  $handler->display->display_options['filters']['birthdate']['expose']['label'] = 'Birth Date';
  $handler->display->display_options['filters']['birthdate']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['birthdate']['expose']['operator'] = 'birthdate_op';
  $handler->display->display_options['filters']['birthdate']['expose']['identifier'] = 'birthdate';
  $handler->display->display_options['filters']['birthdate']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hamster Habitat: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'hamster_habitat';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'habitat_id';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Habitat';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hamster-view';
  
  // Store the saved view into the array.
  $views[$view->name] = $view;
  
  return $views;
}

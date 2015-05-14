<?php

function even_nodes_views_query_alter(&$view, &$query) {
  // kpr() causes problems within in the edit views UI.
  // dpm($view);
  // dpm($query);
  
  // Really wide net and update any view of nodes.
  if ($view->base_table == 'node') 
  
  if ($view->name == 'node_list') {
    // For simple where clauses.
    //$query->add_where(1, 'node.nid', 5);
    
    // For more complex where clauses.
    $query->add_where_expression(1, 'node.nid % 2 = 0');
  }
  
  // dpm($query);
}

function even_nodes_views_pre_render(&$view) {
  // dpm($view->result);
  
  if ($view->name == 'node_list') {
    foreach($view->result as $key => $value ) {
      $value->node_title = 'Title: ' . $value->node_title;
      $view->result[$key] = $value;
    }
  }

  // dpm($view->result);
}

function even_nodes_views_post_render(&$view, &$output, &$cache) {
  if ($view->name == 'node_list') {
    $output = '<div style="background-color: pink">' . $output . '</div>';
    // dpm($output);
  }
  
}
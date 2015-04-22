<?php

function node_metadata_page($node) {  
  $configs = array();
  $configs[] = array(
    'key' => 'name',
    'label' => 'Author',
  ); 
  $configs[] = array(
    'key' => 'created',
    'label' => 'Created',
    'format' => 'format_date',
  );
  $configs[] = array(
    'key' => 'changed',
    'label' => 'Updated',
    'format' => 'format_date',
  );
  $configs[] = array(
    'key' => 'comment_count',
    'label' => 'Comment count',
  );
  
  $output = '';
  foreach ($configs as $config) {
    $key = $config['key'];
    $label = $config['label'];
    $value = $node->$key;
    
    $format = empty($config['format']) ?  '' : $config['format'];
    if (!empty($format)) {
      $value = $format($value);
    }
    
    $output .= '<div><label>' . $label . ':</label>' . $value . '</div>';
  }
  
  return $output;
}



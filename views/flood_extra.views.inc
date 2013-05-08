<?php

/**
   * @file
   * Views integration for the flood_extra custom module
   */
  
  /**
   * Implements hook_views_data()
   *
   */
  function flood_extra_views_data() {
  
    $data = array();
  $data['flood']['table']['group'] = t('Flood');

  $data['flood']['table']['join']['users'] = array(
    'left_field' => 'uid',
    'field' => 'identifier',
  );

  $data['users']['flood_rel'] = array(
    'real field' => 'identifier',
    'title' => t('flooded user'),
    'group' => t('Flood'),
    'help' => t('An flooded user'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'flood',
      'base field' => 'identifier',
      'label' => t('Flood'),
      'relationship field' => 'identifier',
    ),
  );

  $data['flood']['event'] = array(
    'title' => t('Event'),
	  'help' => t('Event name.'),
	  'field' => array(
	    'handler' => 'views_handler_field',
	    'click sortable' => TRUE,
	  ),
	  'filter' => array(
	    'handler' => 'views_handler_filter_numeric',
	    'allow empty' => TRUE,
	  ),
	  'argument' => array(
	    'handler' => 'views_handler_argument_numeric',
	  ),
	  'sort' => array(
	    'handler' => 'views_handler_sort',
	  ),
  );


  $data['flood']['identifier'] = array(
      'title' => t('User ID'),
      'help' => t('Flooded User ID.'),
      'field' => array(
        'handler' => 'views_handler_field_user',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_user_name',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_user_uid',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'relationship' => array(
        'base' => 'users',
        'base_field' => 'identifier',
        'handler' => 'views_handler_relationship',
        'label' => t('Acceptances to user relationship'),
      ),
    );

  
	
  return $data;
}

<?php

/**
 * @file
 * Internationalization (i18n) integration for the Commerce Flat Rate module.
 */

/**
 * Implements hook_i18n_object_info().
 */
function commerce_flat_rate_i18n_object_info() {
  $info['commerce_flat_rate'] = array(
    'title' => t('Commerce Flat Rate'),
    'key' => 'name',
    'class' => 'i18n_string_object_wrapper',
    'string translation' => array(
      'textgroup' => 'commerce_flat_rate',
      'type' => 'name',
      'properties' => array(
        'title' => t('Title'),
        'display_title' => t('Display title', array(), array('context' => 'title for display purposes')),
        'description' => t('Description'),
      ),
    ),
  );
  return $info;
}

/**
 * Implements hook_i18n_string_info().
 */
function commerce_flat_rate_i18n_string_info() {
  $groups['commerce_flat_rate'] = array(
    'title' => t('Commerce Flat Rate'),
    'description' => t('Commerce Flat Rate shipping service titles, display titles, and descriptions.'),
    'format' => FALSE, // This group doesn't have strings with format
    'list' => FALSE, // This group cannot list all strings
  );
  return $groups;
}

/**
 * Implements hook_i18n_string_objects().
 */
function commerce_flat_rate_i18n_string_objects($type) {
  if ($type == 'commerce_flat_rate') {
    return db_select('commerce_flat_rate_service', 'cfrs')
      ->fields('cfrs', array('name', 'title', 'display_title', 'description'))
      ->execute()
      ->fetchAllAssoc('name', PDO::FETCH_ASSOC);
  }
}

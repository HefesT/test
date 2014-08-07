<?php

/**
 * @file
 * Internationalization (i18n) integration for the Commerce tax module.
 */

/**
 * Implements hook_i18n_object_info().
 */
function commerce_tax_i18n_object_info() {
  $info['commerce_tax_rate'] = array(
    'title' => t('Commerce tax rate'),
    'key' => 'rules_component',
    'class' => 'i18n_object_wrapper',
    'string translation' => array(
      'textgroup' => 'commerce',
      'type' => 'name',
      'properties' => array(
        'title' => t('Title'),
        'display_title' => t('Display title', array(), array('context' => 'title for display purposes')),
        'description' => t('Description'),
      ),
    ),
  );
  $info['commerce_tax_type'] = array(
    'title' => t('Commerce tax type'),
    'key' => 'rule',
    'class' => 'i18n_object_wrapper',
    'string translation' => array(
      'textgroup' => 'commerce',
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
 * Implements hook_i18n_string_objects().
 */
function commerce_tax_i18n_string_objects($type) {
  if ($type == 'commerce_tax_rate') {
    $query = db_select('commerce_tax_rate', 'ctr')
      ->fields('ctr', array('name', 'title', 'display_title', 'description'));
    $query->addExpression("CONCAT('commerce_tax_rate_', ctr.name)", 'rules_component');
    return $query->execute()
      ->fetchAllAssoc('rules_component', PDO::FETCH_ASSOC);
  }
  if ($type == 'commerce_tax_type') {
    $query = db_select('commerce_tax_type', 'ctt')
      ->fields('ctt', array('name', 'title', 'display_title', 'description'));
    $query->addExpression("CONCAT('commerce_tax_type_', ctt.name)", 'rule');
    return $query->execute()
      ->fetchAllAssoc('rule', PDO::FETCH_ASSOC);
  }
}
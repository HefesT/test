<?php
/**
 * @file
 * Commerce hook implementations for the Commerce Reverse Payments module.
 */

/**
 * Implements hook_commerce_payment_method_info().
 */
function commerce_reverse_payments_commerce_payment_method_info() {
  return array(
    'reverse' => array(
      'base' => 'commerce_reverse_payments',
      'title' => t('Reverse payment'),
      'short_title' => t('Reverse'),
      'display_title' => t('Reverse payment'),
      'description' => t('Reverse an existing payment.'),
      'file' => 'includes/commerce_reverse_payments.callbacks.inc',
    ),
  );
}

/**
 * Implements hook_commerce_payment_transaction_delete().
 *
 * When a reverse payment transaction is deleted we need to make sure the origin
 * transaction is no longer reversed.
 */
function commerce_reverse_payments_commerce_payment_transaction_delete($transaction) {
  if ('reverse' == $transaction->payment_method) {
    $reversed_transaction = commerce_payment_transaction_load($transaction->data['original_transaction']);
    if ($reversed_transaction) {
      $reversed_transaction->data['reversed'] = FALSE;
      commerce_payment_transaction_save($reversed_transaction);
    }
  }
}

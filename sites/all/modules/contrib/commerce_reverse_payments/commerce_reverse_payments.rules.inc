<?php
/**
 * @file
 * Rules integration for the Commerce Reverse Payments module.
 */

/**
 * Implements hook_rules_event_info().
 */
function commerce_reverse_payments_rules_event_info() {
  return array(
    'commerce_reverse_payments_payment_reversed' => array(
      'label' => t("Initial payment is added to the user's cart."),
      'group' => t('Commerce Reverse Payments'),
      'variables' => array(
        'reversed_transaction' => array(
          'type' => 'commerce_payment_transaction',
          'label' => t('Reversed Payment Transaction'),
          'description' => t('The payment transaction that was reversed.'),
        ),
        'reverse_transaction' => array(
          'type' => 'commerce_payment_transaction',
          'label' => t('Reverse Payment Transaction'),
          'description' => t('The payment transaction created to reverse the payment.'),
        ),
      ),
    ),
  );
}

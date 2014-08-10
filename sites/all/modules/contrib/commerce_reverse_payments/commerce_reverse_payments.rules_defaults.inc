<?php
/**
 * @file
 * Default rule configurations for the Commerce Reverse Payments module.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_reverse_payments_default_rules_configuration() {
  $rules = array();

  // Add a reaction rule to set the order's status to "pending".
  $rule = rules_reaction_rule();
  $rule->event('commerce_reverse_payments_payment_reversed');
  $rule->label = t('Set order status back to pending if it was compelted when a payment was reversed.');
  $rule->active = TRUE;

  // We only want to change the status if the order has been completed.
  $rule->condition(
    'data_is',
    array(
      'data:select' => 'reversed-transaction:order:state',
      'value' => 'completed',
    )
  );

  // Update the order's status to pending.
  $rule->action(
    'commerce_order_update_state',
    array(
      'commerce_order:select' => 'reversed-transaction:order',
      'order_state' => 'pending',
    )
  );

  $rules['commerce_reverse_payments_update_order_status'] = $rule;

  return $rules;
}

<?php
/**
 * @file
 * API documentation for hooks provided by the Commerce Reverse Payments module.
 */

/**
 * Allow modules to react when a payment transaction has been reversed.
 *
 * @param stdClass $reversed_transaction
 *   Commerce payment transaction entity that was reversed.
 * @param stdClass $reverse_transaction
 *   Commerce payment transaction entity that was created to reverse the
 *   payment.
 */
function hook_commerce_reverse_payments_payment_reversed($reversed_transaction, $reverse_transaction) {
  // Set the order's status to pending.
  commerce_order_status_update(commerce_order_load($reversed_transaction->order_id), 'pending');
}

<?php
/**
 * @file
 * Commerce payment method callbacks for the Commerce Reverse Payments module.
 */

/**
 * Payment method callback: checkout form.
 */
function commerce_reverse_payments_submit_form($payment_method, $pane_values, $checkout_pane, $order) {
  // If there are no payments that can be reveresed, let the user know an do not
  // bother with the rest of the form.
  $transactions = _commerce_reverse_payments_reverse_payment_options($order);
  if (empty($transactions)) {
    return array(
      'no_transactions' => array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('There are no payments that can be reversed.') . '</p>',
      ),
    );
  }

  return array(
    'transaction' => array(
      '#type' => 'select',
      '#title' => t('Payment'),
      '#options' => $transactions,
      '#description' => t('Select the payment that should be reversed.'),
      '#required' => TRUE,
    ),
    'comment' => array(
      '#type' => 'textarea',
      '#title' => t('Comment'),
      '#default_value' => (isset($pane_value['comment']) ? $pane_value['comment'] : NULL),
      '#description' => t('Explanation for why the payment was reversed.'),
      '#required' => TRUE,
    ),
  );
}

/**
 * Payment method callback: submit form submission.
 */
function commerce_reverse_payments_submit_form_submit($payment_method, $pane_form, $pane_values, $order, $charge) {
  commerce_reverse_payments_reverse_payment(commerce_payment_transaction_load($pane_values['transaction']), $pane_values['comment']);
}

<?php

/**
 * @file
 * Page preprocessing.
 */

/**
 * Preprocess page display.
 */
function radikal_fishing_theme_alpha_preprocess_page(&$vars) {
  if ($vars['is_front']) {
    unset($vars['page']['content']['content']['content']['system_main']['default_message']);
  }
}

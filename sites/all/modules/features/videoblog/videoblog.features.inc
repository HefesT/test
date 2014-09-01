<?php
/**
 * @file
 * videoblog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function videoblog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function videoblog_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function videoblog_node_info() {
  $items = array(
    'blog_video_post' => array(
      'name' => t('Blog Video Post'),
      'base' => 'node_content',
      'description' => t('Use <em>blog video post</em> to write regular content with an embeded video. (Vimeo or Youtube)
'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

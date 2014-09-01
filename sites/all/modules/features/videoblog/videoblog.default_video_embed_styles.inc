<?php
/**
 * @file
 * videoblog.default_video_embed_styles.inc
 */

/**
 * Implements hook_default_video_embed_styles().
 */
function videoblog_default_video_embed_styles() {
  $export = array();

  $video_embed_style = new stdClass();
  $video_embed_style->disabled = FALSE; /* Edit this to true to make a default video_embed_style disabled initially */
  $video_embed_style->api_version = 1;
  $video_embed_style->name = 'video_banner_front';
  $video_embed_style->title = 'Video Banner Front';
  $video_embed_style->data = array(
    'youtube' => array(
      'width' => '460px',
      'height' => '260px',
      'theme' => 'dark',
      'autoplay' => 0,
      'vq' => 'large',
      'rel' => 0,
      'showinfo' => 0,
      'modestbranding' => 0,
      'iv_load_policy' => '1',
      'autohide' => '1',
    ),
    'vimeo' => array(
      'width' => '460px',
      'height' => '260px',
      'color' => '00adef',
      'portrait' => 1,
      'title' => 1,
      'byline' => 1,
      'autoplay' => 0,
      'loop' => 0,
    ),
    'data__active_tab' => 'edit-data-vimeo',
  );
  $export['video_banner_front'] = $video_embed_style;

  return $export;
}

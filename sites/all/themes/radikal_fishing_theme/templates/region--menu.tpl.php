<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <?php // if ($main_menu || $secondary_menu): ?>
    <nav class="navigation">
      <!--<div class="primary-menu inline">-->
        <?php // print theme('links__system_main_menu', array('prefix' => '<div>', 'links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix', 'main-menu')), 'heading' => array('text' => t('Main menu'),'level' => 'h2','class' => array('element-invisible')))); ?>
<!--      </div>
      --><div class="second-menu block"> 
       <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix', 'secondary-menu')), 'heading' => array('text' => t('Secondary menu'),'level' => 'h2','class' => array('element-invisible')))); ?>
      </div>
      <?php // print theme('links__system_product_category_menu', array('links' => $product_category, 'attributes' => array('id' => 'product-category', 'class' => array('links', 'inline', 'clearfix', 'product-category')), 'heading' => array('text' => t('Product category menu'),'level' => 'h2','class' => array('element-invisible')))); ?>
        <?php print $content; ?>
      
    </nav>
    <?php // endif; ?>
    <?php // print $content; ?>
  </div>
</div>

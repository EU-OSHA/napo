<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="multicarousel--block" id="multicarouselBlock1" data-items="1,2,3,3" data-slide="3" data-interval="1000">
  <?php if ($rows): ?>
    <div class="multicarousel--block--inner">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
<button class="btn btn-primary leftLst over"><img src="/sites/all/themes/napo_frontend/images/slider-left.png" title="show more"></button>
<button class="btn btn-primary rightLst"><img src="/sites/all/themes/napo_frontend/images/slider-right.png" title="show more"></button>
</div>

<script type="text/javascript">

	jQuery(document).ready(function(){
	    if (jQuery(window).width() >= 992) {
	        jQuery(".multicarousel--block").attr("data-slide","3");
	    }  
	});
	
	jQuery(window).resize(function () {
        if (jQuery(window).width() >= 992) {
            jQuery(".multicarousel--block").attr("data-slide","3");
        }
	}); 


    jQuery(document).ready(function(){
	    if (jQuery(window).width() <= 991) {
	        jQuery(".multicarousel--block").attr("data-slide","2");
	    }  
	});
	
	jQuery(window).resize(function () {
        if (jQuery(window).width() <= 991) {
            jQuery(".multicarousel--block").attr("data-slide","2");
        }
	}); 

	jQuery(document).ready(function(){
	    if (jQuery(window).width() <= 767) {
	        jQuery(".multicarousel--block").attr("data-slide","1");
	    }  
	});
	
	jQuery(window).resize(function () {
        if (jQuery(window).width() <= 767) {
            jQuery(".multicarousel--block").attr("data-slide","1");
        }
	}); 

</script>
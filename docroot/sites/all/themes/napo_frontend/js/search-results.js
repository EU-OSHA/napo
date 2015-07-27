jQuery(document).ready(function () {
    jQuery(".napo-film-video-download-form").hide();
    jQuery(".napo-share-widget").hide();
    jQuery(".field-name-node-link").hide();

    jQuery("div.view-content").find("div.views-row").each(function(i){
        jQuery(this).hover(
            function(){
                jQuery(this).find(".napo-film-video-download-form").show();
                jQuery(this).find(".napo-share-widget").show();
				jQuery(this).addClass("search-hover");
                // Get Read More link value
                var link = jQuery(this).find(".field-name-node-link").find('a').attr('href');
				// Read more text
                var readmore= Drupal.t('Read more');
                //add Read More Button
                if (link){
                    if(jQuery(this).find(".read_more_button").length){
                        jQuery(this).find(".read_more_button").show();
                    }else{
                        var css_class = 'glyphicon glyphicon-envelope view-film-details-icon';
                        if(jQuery(this).find(".node-napo-video").length){
                            css_class = 'glyphicon glyphicon-play-circle view-film-details-icon';
							jQuery(this).append('<div class="read_more_button"><a href="'+link+'"><span class="'+css_class+'"></span></a></div>');
                        }else{
                        jQuery(this).append('<div class="read_more_button"><a href="'+link+'"><span class="'+css_class+'">'+readmore+'</span></a></div>');
						}
                    }
                }
            }
        )
        jQuery(this).mouseleave(
            function(){
                jQuery(this).find(".napo-film-video-download-form").hide();
                jQuery(this).find(".napo-share-widget").hide();
                jQuery(this).find(".read_more_button").hide();
				jQuery(this).removeClass("search-hover");
            }
        )
    });
});
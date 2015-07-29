//Fixing responsive menu to iPhone
jQuery(document).ready(function() {
    jQuery(".dropdown-toggle").dropdown();
});

//Contact Us
jQuery(document).ready(function () {
	var hiddenContent = jQuery(".webform-client-form");
	jQuery(".webform-client-form").css("display","none");
	jQuery(".contact-form-widget-container h2").click(
		function( event ){
			event.preventDefault();
			if (hiddenContent.is(":visible")){
				hiddenContent.slideUp();
				jQuery(".contact-form-widget-container h2").css("bottom","-10px");
				jQuery(".contact-form-widget-container h2").removeClass("desplegado");
				jQuery(".imagen_disabled").removeClass("imagen_disabled");
			} else {
				hiddenContent.slideDown();
				jQuery(".contact-form-widget-container h2").css("bottom","532px");
				jQuery(".contact-form-widget-container h2").addClass("desplegado");
				jQuery( "body" ).append( "<div class='imagen_disabled'></div>" );
			}
		}
	);
});

// Footer carousel responsive design
var isVisible = true;
	jQuery(document).ready(function() {
		jQuery('#block-views-consortium-partners-block-1 div').hide();
	    jQuery("#consortium-partners-block-1-link").click(function() {
	        if(isVisible){
	            jQuery("#block-views-consortium-partners-block-1 div").slideDown();
	            jQuery(this).text(Drupal.t('Close'));
	            isVisible = false;
	        } else {
	            jQuery("#block-views-consortium-partners-block-1 div").slideUp();
	            jQuery(this).text(Drupal.t('See details'));
	            isVisible = true;
	        }
	    });
	});

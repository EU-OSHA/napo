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
				jQuery(".contact-form-widget-container h2").css("bottom","515px");
				jQuery(".contact-form-widget-container h2").addClass("desplegado");
				jQuery( "body" ).append( "<div class='imagen_disabled'></div>" );
			}
		}
	);
});
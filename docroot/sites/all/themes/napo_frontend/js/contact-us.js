jQuery(document).ready(function () { 	
	var hiddenContent = jQuery(".webform-client-form");
	jQuery(".webform-client-form").css("display","none");
	jQuery(".contact-form-widget-container h2").click(
		function( event ){
			event.preventDefault();
			if (hiddenContent.is(":visible")){
				hiddenContent.slideUp();
				jQuery(".contact-form-widget-container h2").css("bottom","-2%");
				jQuery(".contact-form-widget-container h2").removeClass("desplegado");
			} else {
				hiddenContent.slideDown();
				jQuery(".contact-form-widget-container h2").css("bottom","64%");
				jQuery(".contact-form-widget-container h2").addClass("desplegado");
			}
		}
	);
});
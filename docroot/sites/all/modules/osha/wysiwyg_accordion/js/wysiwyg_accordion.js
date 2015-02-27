(function ($){
	Drupal.behaviors.wysiwyg_accordion_theme_createAccordions = {
		attach:function (context) {
            $( "div.wysiwyg_accordion" ).accordion({
                heightStyle: "content",
                collapsible: true,
                animate: false
            });
		}
	}
}(jQuery));



(function ($) {
	
	/**
	 * Determine a unique selector for the given element
	 */
	$.fn.extend({
		getPath: function(path) {
			
			// The first time this function is called, path won't be defined.
			if ( typeof path == 'undefined' ) path = '';

			// If this element is <html> we've reached the end of the path.
			if ( this.is('html') )
				return 'html' + path;

			// Add the element name.
			var cur = this.get(0).nodeName.toLowerCase();

			// Determine the IDs and path.
			var id    = this.attr('id');
			var aClass = this.attr('class');

			// Add the #id if there is one.
			if ( typeof id != 'undefined' )
				cur += '#' + id;

			// Add any classes.
			if ( typeof aClass != 'undefined' )
				cur += '.' + aClass.split(/[\s\n]+/).join('.');

			if ($(cur + path).length <= 1) {
				return cur + path;
			} else {
			// Recurse up the DOM.
				return this.parent().getPath( ' > ' + cur + path );
			}
		}
	});
	
  Drupal.behaviors.search_autocomplete_admin = {

    attach: function(context) {
    	
    	var input_selector = "input[type='text']:not(.ui-autocomplete-processed):not(.form-autocomplete)";
    	var selector = '';
    	
    	$("<ul id='sa_admin_menu'><div class='sa_title'>Search Aucomplete</div><li class='sa_add'>" + Drupal.t('add autocompletion') + "</li></ul>").appendTo( $('body') );
    	
    	$(input_selector).live("mouseover", function (event) {
    		var offset = $(this).offset();
    		
    		// display the context menu
        $("#sa_admin_menu").show();
        $('#sa_admin_menu').css('left', offset.left + $(this).width() - 5);
        $('#sa_admin_menu').css('top', offset.top + $(this).height() - 5);
        $('#sa_admin_menu').css('display','inline');     
        $("#sa_admin_menu").css("position", "absolute");
        
        // find element unique selector
        selector = $(this).getPath();
        
    	});
    	
    	// hide the menu when out or used
    	$(input_selector).live("click", function () {
    		$("#sa_admin_menu").hide();
    	});
			$(input_selector).live("mouseout", function () {
				$("#sa_admin_menu").hide();
			});
			
			// hide the menu when out
			$("#sa_admin_menu").live("mouseover", function(){
				$(this).show();
			});
			$("#sa_admin_menu").live("mouseout", function(){
				$(this).hide();
			});
			
			// add a new autocompletion
			$(".sa_add").live("click", function () {
				window.location = 'index.php?q=admin/config/search/search_autocomplete/add&selector=' + encodeURI(selector.replace('#', '%23'));
    	});
			
    }
  };
})(jQuery);
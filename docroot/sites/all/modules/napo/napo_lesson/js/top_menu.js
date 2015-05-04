jQuery('document').ready(function() {
    // Affix class to right nav menu
    jQuery('#top_menu_lessons').affix({
        offset: {
            top: function () {
                return (this.top = jQuery('#top_menu_lessons').parent().offset().top - 30);
            },
            bottom: function () {
                return (this.bottom = jQuery('.footer').outerHeight(true) + 17);
            }
        }
    });
});
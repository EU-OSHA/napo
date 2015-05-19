jQuery('document').ready(function() {
    var menu = jQuery('#menu-about-page-menu');

    // Change first tag from h2 to h3 to be like the rest and remove ':'
    jQuery('.node-lesson .col-md-9 h2').each(function(idx, el) {
        if(jQuery(el).text() != '') {
            var new_text = jQuery(el).text().replace(':', '');
            jQuery(this).replaceWith('<h3>' + new_text + '</h3>');
        }
    });

    // Find sections and append to right menu
    jQuery('h3').each(function(idx, el) {
        if(jQuery(el).text() != '') {
            if(typeof jQuery(el).attr('id') == 'undefined') {
                jQuery(this).attr('id','h2-'+idx);
            }
            var css = idx == 0 ? ' class=" headings active"' : ' class="headings"';
            menu.append(jQuery('<li' + css + '><a href="#' + jQuery(this).attr('id') + '">' + jQuery(el).text() + '</a></li>'));
        }
    });

    // Add fields to affix menu
    add_fields_to_right_menu(menu, '.field-name-field-file');
    add_fields_to_right_menu(menu, '.download_whole_lesson');

    // Spymenu target
    jQuery('body').scrollspy({
        target: '.scrollspy'
    });

    // Affix class to right nav menu
    jQuery('#menu-about-page-menu').affix({
        offset: {
            top: function () {
                return (this.top = jQuery('#menu-about-page-menu').parent().offset().top - 30);
            },
            bottom: function () {
                return (this.bottom = jQuery('.footer').outerHeight(true) + 17);
            }
        }
    });

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

    // Execute on load
    check_width();

    // Execute on resize
    jQuery(window).resize(function(){
        check_width();
    });
});

function add_fields_to_right_menu(menu, field){
    jQuery('.node-lesson .col-md-3').find(field).each(function(i) {
        menu.append(jQuery('<li class="">'+jQuery(this).html()+'</li>'));
        jQuery(this).hide();
    });
}

function check_width() {
    if(jQuery(window).width() < 768) {
        jQuery('.headings').hide();
        jQuery('#group-left').find('.scrollspy').each(function(i) {
            jQuery('#group-right').append('<div class="bottom-right-menu">' + jQuery(this).html() + '</div>');
            jQuery(this).hide();
        });
    }else {
        jQuery('.headings').show();
        jQuery('#group-left .scrollspy').show();
        jQuery('#group-right .bottom-right-menu').remove();
    }
}

jQuery('document').ready(function() {
    var menu = jQuery('#menu-about-page-menu');
    jQuery('h3').each(function(idx, el) {
        if(jQuery(el).text() != '') {
            if(typeof jQuery(el).attr('id') == 'undefined') {
                jQuery(this).attr('id','h2-'+idx);
            }
            var css = idx == 0 ? ' class="active"' : '';
            menu.append(jQuery('<li' + css + '><a href="#' + jQuery(this).attr('id') + '">' + jQuery(el).text() + '</a></li>'));
        }
    });

    jQuery(document.body).scrollspy({
        target: '#affix-menu'
    });

    jQuery('#affix-menu').affix({
        offset: {
            top: function () {
                return (this.top = jQuery('#affix-menu').parent().offset().top - 20);
            },
            bottom: function () {
                return (this.bottom = jQuery('.footer').outerHeight(true) + 17);
            }
        }
    });
});
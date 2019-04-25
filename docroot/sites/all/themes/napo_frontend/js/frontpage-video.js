jQuery(document).ready(function () {
    jQuery("div.view.view-frontpage-custom-video.view-id-frontpage_custom_video.view-display-id-block").click( function (event) {
        if (jQuery("div.video-js.vjs-default-skin").hasClass("vjs-playing")){
            jQuery("div.views-field.views-field-nothing.frontpage-video-title").show();
        } else {
            jQuery("div.views-field.views-field-nothing.frontpage-video-title").hide();
        }
    });
});

jQuery(document).ready(function () {

    if( jQuery('.btn-back').length > 0 ){
        jQuery('.page--banner--block h1').css('margin-top','5rem');
    }

});

/** CAROUSEL **/
jQuery(document).ready(function () {
    var itemsMainDiv = ('.multicarousel--block');
    var itemsDiv = ('.multicarousel--block--inner');
    var itemWidth = "";

    jQuery('.leftLst, .rightLst').click(function () {
        var condition = jQuery(this).hasClass("leftLst");
        if (condition)
            click(0, this);
        else
            click(1, this)
    });

    ResCarouselSize();

    jQuery(window).resize(function () {
        ResCarouselSize();
    });

    //this function define the size of the items
    function ResCarouselSize() {
        var incno = 0;
        var dataItems = ("data-items");
        var itemClass = ('.item');
        var id = 0;
        var btnParentSb = '';
        var itemsSplit = '';
        var sampwidth = jQuery(itemsMainDiv).width();
        var bodyWidth = jQuery('body').width();
        jQuery(itemsDiv).each(function () {
            id = id + 1;
            var itemNumbers = jQuery(this).find(itemClass).length;
            btnParentSb = jQuery(this).parent().attr(dataItems);
            itemsSplit = btnParentSb.split(',');
            jQuery(this).parent().attr("id", "multicarouselBlock" + id);


            if (bodyWidth >= 1200) {
                incno = itemsSplit[3];
                itemWidth = sampwidth / incno;
            }
            else if (bodyWidth >= 992) {
                incno = itemsSplit[2];
                itemWidth = sampwidth / incno;
            }
            else if (bodyWidth >= 768) {
                incno = itemsSplit[1];
                itemWidth = sampwidth / incno;
            }
            else {
                incno = itemsSplit[0];
                itemWidth = sampwidth / incno;
            }
            jQuery(this).css({ 'transform': 'translateX(0px)', 'width': itemWidth * itemNumbers });
            jQuery(this).find(itemClass).each(function () {
                jQuery(this).outerWidth(itemWidth);
            });

            jQuery(".leftLst").addClass("over");
            jQuery(".rightLst").removeClass("over");

        });
    }


    //this function used to move the items
    function ResCarousel(e, el, s) {

        var leftBtn = ('.leftLst');
        var rightBtn = ('.rightLst');
        var translateXval = '';
        var divStyle = jQuery(el + ' ' + itemsDiv).css('transform');
        var values = divStyle.match(/-?[\d\.]+/g);
        var xds = Math.abs(values[4]);
        if (e == 0) {
            translateXval = parseInt(xds) - parseInt(itemWidth * s);
            jQuery(el + ' ' + rightBtn).removeClass("over");

            if (translateXval <= itemWidth / 2) {
                translateXval = 0;
                jQuery(el + ' ' + leftBtn).addClass("over");
            }
        }
        else if (e == 1) {
            var itemsCondition = jQuery(el).find(itemsDiv).width() - jQuery(el).width();
            translateXval = parseInt(xds) + parseInt(itemWidth * s);
            jQuery(el + ' ' + leftBtn).removeClass("over");

            if (translateXval >= itemsCondition - itemWidth / 2) {
                translateXval = itemsCondition;
                jQuery(el + ' ' + rightBtn).addClass("over");
            }
        }
        jQuery(el + ' ' + itemsDiv).css('transform', 'translateX(' + -translateXval + 'px)');
    }

    //It is used to get some elements from btn
    function click(ell, ee) {
        var Parent = "#" + jQuery(ee).parent().attr("id");
        var slide = jQuery(Parent).attr("data-slide");
        ResCarousel(ell, Parent, slide);
    }

});


/** ACORDION **/
jQuery(document).ready(function () {

    function acordionOpen(elem){
       var contentDiv = jQuery(elem).next();
       var parentDiv = jQuery(elem).parent();
       
       if ( parentDiv.hasClass("active")) {
           jQuery(contentDiv).slideUp(600).fadeOut(600);
           jQuery(parentDiv).removeClass('active');
           jQuery(elem).removeClass('active');
       } else {
           jQuery('.acordion--block--item').removeClass('active');
           jQuery('.acordion-content-title').removeClass('active');
           jQuery('.acordion-content-text').slideUp(600);
           jQuery(contentDiv).slideDown(600).fadeIn(600);
           jQuery(parentDiv).addClass('active');
           jQuery(elem).addClass('active');
       }
    }

    jQuery('.acordion--block h3').click(function () {
        acordionOpen( this );
    });
});




/** MENU RESPONSIVE **/
jQuery(document).ready(function () {

    jQuery('#search-block-form').on('submit', function(e){
        e.preventDefault();
        value = jQuery('#edit-search-block-form--2').val();
        alert('Searching... "'+ value + '"');
    });

    mobileDevice(screen.width); 

    function mobileDevice(screen){

        if( screen < 767 ){
            
            if( jQuery(".search--lang--block").parent().attr('class') != 'navbar--toggle--button'){
                jQuery(".search--lang--block").appendTo(".navbar--toggle--button");

                jQuery('.btn-search-mobile').click(function () {
                    jQuery('#block-search-form').toggleClass('in');
                });

                jQuery('.btn-primary[type=button]').click(function () {
                    if( jQuery('#edit-search-block-form--2').val().length > 0) {
                        jQuery('#search-block-form').submit();
                        jQuery('#block-search-form').removeClass('in');
                        jQuery('#edit-search-block-form--2').val('');
                    } else {
                        jQuery('#block-search-form').removeClass('in');
                    }
                });
            }


            jQuery('button.navbar-toggle').click(function () {
                jQuery('#block-search-form').removeClass('in');
                if( jQuery('.menu--search--block > .navbar-collapse').hasClass('in') ){
                    jQuery('.menu li.dropdown').removeClass('in');
                }
            });

            jQuery('.menu li.dropdown span').click(function () {
                element = jQuery(this).parent();
                if(element.hasClass('in')){
                    jQuery('.menu li.dropdown').removeClass('in');
                } else {
                    jQuery('.menu li.dropdown').removeClass('in');
                    jQuery( element ).addClass('in');
                }            
            });



        
        } else {
            jQuery('#block-search-form').removeClass('in');
            jQuery('.menu li.dropdown').removeClass('in');
            jQuery(".search--lang--block").appendTo(".nav-main-menu");
        }

    }

    jQuery(window).on("resize",function(e){
        e.preventDefault();
        jQuery('#block-search-form').removeClass('in');
        mobileDevice(screen.width);    
         //mobileDevice( jQuery(window).width() );
    });
        
});

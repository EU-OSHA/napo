/**
 * @file
 * SEARCH AUTOCOMPLETE (version 7.3-x)
 */

/*
 * Sponsored by:
 * www.axiomcafe.fr
 */

(function ($) {
  
  // Autocomplete
  $.ui.autocomplete.prototype._renderItem = function (ul, item) {
    var term = this.term;
    var first = ("group" in item)  ? 'first' : '';
    var innerHTML = '<div class="ui-autocomplete-fields ' + first + '">';
    if (item.fields) {
      $.each( item.fields, function( key, value ) {
      var regex = new RegExp( '(' + $.trim(term) + ')', 'gi' );
    	var output = value;
		if (value.indexOf('src=') == -1 && value.indexOf('href=') == -1) {
		  output = value.replace(regex, "<span class='ui-autocomplete-field-term'>$1</span>");
		}
        innerHTML += ('<div class="ui-autocomplete-field-' + key + '">' + output + '</div>');
      });
    } else {
    	// Case no results :
    	innerHTML += ('<div class="ui-autocomplete-field-noresult">' + item.label + '</div>');
    }
    innerHTML += '</div>';

    var group = '';
    if ("group" in item) {
    	group += ('<div class="ui-autocomplete-field-group ' + item.group.group_id + '">' + item.group.group_name + '</div>');
    	$(group).appendTo( ul );
    }
    return  $("<li class=ui-menu-item-" + first + "></li>" )
        .data( "item.autocomplete", item )
        .append( "<a>" + innerHTML + "</a>" )
        .appendTo( ul );
  };
  
  $.ui.autocomplete.prototype._resizeMenu = function() {
    var ul = this.menu.element; 
    ul.outerWidth(Math.max( ul.width("").outerWidth() + 5, this.options.position.of == null ? this.element.outerWidth() : this.options.position.of.outerWidth()));
  };
  
  Drupal.behaviors.search_autocomplete = {
    attach: function(context) {
      if (Drupal.settings.search_autocomplete) {
        $.each(Drupal.settings.search_autocomplete, function(key, value) {
          var NoResultsLabel = Drupal.settings.search_autocomplete[key].no_results;
          $(Drupal.settings.search_autocomplete[key].selector).addClass('ui-autocomplete-processed ui-theme-' + Drupal.settings.search_autocomplete[key].theme).autocomplete({
            minLength: Drupal.settings.search_autocomplete[key].minChars,
            source: function(request, response) {
              // External URL:
              if (Drupal.settings.search_autocomplete[key].type == 'external') {
                $.getJSON(Drupal.settings.search_autocomplete[key].datas, { q: request.term }, function (results) {
                  // Only return the number of values set in the settings.
                  if (!results.length && NoResultsLabel) {
                      results = [NoResultsLabel];
                  }
                  response(results.slice(0, Drupal.settings.search_autocomplete[key].max_sug));
                });
              }
              // Internal URL:
              else if (Drupal.settings.search_autocomplete[key].type == 'internal' || Drupal.settings.search_autocomplete[key].type == 'view') {
                $.getJSON(Drupal.settings.search_autocomplete[key].datas + encodeURI(request.term), { }, function (results) {
                  // Only return the number of values set in the settings.
                  if (!results.length && NoResultsLabel) {
                      results = [NoResultsLabel];
                  }
                  response(results.slice(0, Drupal.settings.search_autocomplete[key].max_sug));
                });
              }
              // Static resources:
              else if (Drupal.settings.search_autocomplete[key].type == 'static') {
                var results = $.ui.autocomplete.filter(Drupal.settings.search_autocomplete[key].datas, request.term);
                    if (!results.length && NoResultsLabel) {
                    results = [NoResultsLabel];
                }
                // Only return the number of values set in the settings.
                response(results.slice(0, Drupal.settings.search_autocomplete[key].max_sug));
              }
            },
            open: function(event, ui) {
              $(".ui-autocomplete li.ui-menu-item:odd").addClass("ui-menu-item-odd");
              $(".ui-autocomplete li.ui-menu-item:even").addClass("ui-menu-item-even");
            },
            select: function(event, ui) {
              if (ui.item.label === NoResultsLabel) {
                event.preventDefault();
              } else if (Drupal.settings.search_autocomplete[key].auto_redirect == 1 && ui.item.link) {
                document.location.href = ui.item.link;
              } else if (Drupal.settings.search_autocomplete[key].auto_submit == 1) {
                  $(this).val(ui.item.label);
                  $(this).closest("form").submit();
              }
            },
            focus: function (event, ui) {
              if (ui.item.label === NoResultsLabel) {
                  event.preventDefault();
              }
            },
            appendTo: $(Drupal.settings.search_autocomplete[key].selector).parent(),
          }).autocomplete("widget").attr("id", "ui-theme-" + Drupal.settings.search_autocomplete[key].theme);
        });
      }
    }
  };
})(jQuery);

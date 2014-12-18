---
layout:     default
title:      Home
id:         index
path:       
---
{% for section in site.pages %}
{% if section.layout == "page" %}
- **{{section.title}}**
{% for anchor in section.anchors %}
    - [{{anchor[1]}}]({{site.baseurl}}{{section.path}}/#{{anchor[0]}})
{% endfor %}
{% endif %}
{% endfor %}

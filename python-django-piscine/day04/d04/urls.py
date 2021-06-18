"""d04 URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from ex00.views import index
from ex01.views import django_intro
from ex01.views import display_intro
from ex01.views import templates_intro

urlpatterns = [
    path('ex00/', index, name='Markdown Cheatsheet'),
    path('ex01/django', django_intro, name='Ex01: Django, framework web.'),
    path('ex01/display', display_intro, name='Ex01: Display process of a static page.'),
    path('ex01/templates', templates_intro, name='Ex01: Template engine.'),
    path('admin/', admin.site.urls),
]

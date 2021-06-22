from django.contrib import admin
from django.conf.urls import url
from django.urls import path, include
from ex.views import homepage, registration
from django.shortcuts import redirect

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', homepage),
    path('registration/', registration),
    path('', include('django.contrib.auth.urls')),
]

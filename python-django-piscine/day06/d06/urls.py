from django.contrib import admin
from django.conf.urls import url
from django.urls import path, include
from ex.views import homepage, registration
from django.shortcuts import redirect
from django.contrib.auth import views as auth_views


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', homepage),
    path('registration/', registration),
    url(r'^login/$', auth_views.LoginView.as_view(redirect_authenticated_user=True)),
    url(r'^logout/$', auth_views.LogoutView.as_view()),
]

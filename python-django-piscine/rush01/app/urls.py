from .views import index, register
from .profile import profile
from django.urls import path
from django.contrib.auth import views as auth_views


urlpatterns = [
    path('', index.index, name='index'),
    path('profile/', profile, name='profile'),
    path('register/', register.register, name='register' ),
    path('login/', auth_views.LoginView.as_view(template_name='ex/login.html', redirect_authenticated_user=True), name='login' ),
    path('logout/', auth_views.LogoutView.as_view(template_name='ex/index.html'), name='logout'),
]

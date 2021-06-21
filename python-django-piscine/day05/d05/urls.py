from django.contrib import admin
from django.urls import path
from ex00.views import init

urlpatterns = [
    path('admin/', admin.site.urls),
    path('ex00/init/', init),
]

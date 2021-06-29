from django.contrib import admin
from django.urls import path
from django.conf.urls.static import static
from .settings import DEBUG, MEDIA_URL, MEDIA_ROOT
from app.views import homepage, objdelete


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', homepage),
    path('delete/<int:id>/', objdelete),
    ] + static(MEDIA_URL, document_root=MEDIA_ROOT)

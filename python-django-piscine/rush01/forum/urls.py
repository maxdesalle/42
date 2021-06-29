from .views import forum, create_post, post_details
from django.urls import path
from django.contrib.auth import views as auth_views

urlpatterns = [
    path('', forum.forum, name='forum'),
    path('create/', create_post.create_post, name='create'),
    path('upvote/<int:id>/', forum.upvote, name='upvote'),
    path('downvote/<int:id>/', forum.downvote, name='downvote'),
    path('delete/<int:id>/', forum.delete, name='delete'),
    path('post/<int:pk>/', post_details.post_details, name='post_details')
]

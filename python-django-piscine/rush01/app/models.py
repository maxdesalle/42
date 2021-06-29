from django.db import models
from django.contrib.auth.models import User


class Profile(models.Model):

    user = models.OneToOneField(User, on_delete=models.CASCADE)
    name = models.CharField(max_length=64, blank=True)
    surname = models.CharField(max_length=64, blank=True)
    email = models.EmailField(max_length=128, blank=True, null=True)
    description = models.TextField(blank=True)


class Post(models.Model):

    id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=64)
    author = models.CharField(max_length=64)
    content = models.TextField()
    date = models.DateField(auto_now_add=True)
    time = models.TimeField(auto_now_add=True)

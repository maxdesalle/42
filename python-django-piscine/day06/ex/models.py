from django.db import models
from django.forms import ModelForm

class Tip(models.Model):
    content = models.TextField()
    author = models.CharField(max_length=64)
    date = models.DateField(null=True)
    upvote = models.CharField(max_length=1, default=False)
    downvote = models.CharField(max_length=1, default=False)
    delete = models.CharField(max_length=1, default=False)
    upstats = models.SmallIntegerField(default=0)
    downstats = models.SmallIntegerField(default=0)

from django.db import models
from django.forms import ModelForm

class Tip(models.Model):
    content = models.TextField()
    author = models.CharField(max_length=64)
    date = models.DateField(null=True)

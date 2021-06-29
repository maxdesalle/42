from django.db import models
from django.forms import ModelForm


class Flash(models.Model):

    title = models.CharField(max_length=256)
    img = models.ImageField(upload_to='images/', unique=True)
    delete = models.CharField(max_length=1, default=False)

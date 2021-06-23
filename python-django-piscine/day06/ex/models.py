from django.db import models
from django.forms import ModelForm

class Tip(models.Model):
    content = models.TextField(help_text="Your tip")
    author = models.CharField(max_length=64, help_text="Your username")
    date = models.DateField(null=True, help_text="Today's date")

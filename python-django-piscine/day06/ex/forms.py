from django import forms

from .models import Tip

class TipForm(forms.ModelForm):
    class Meta:
        model = Tip
        fields = ['content', 'author', 'date']

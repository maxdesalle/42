from django.shortcuts import render, redirect
from django.conf import settings
from django.contrib import messages
from .models import Profile
from .forms import ProfileForm
import random


def profile(request):

    context = {}
    data = Profile.objects.filter(user=request.user).first()
    if request.method == 'POST':
        p_form = ProfileForm(request.POST, instance=data)
        if p_form.is_valid():
            profile = p_form.save(commit=False)
            profile.user = request.user
            profile.save()
            return redirect('/profile')
        else:
            p_form = ProfileForm(instance=data)
            context.update({'p_form': p_form})
            return render(request, 'ex/profile.html', context)
    else:
        p_form = ProfileForm(instance=data)
        context.update({'p_form': p_form})
        return render(request, 'ex/profile.html', context)

    return render(request, 'ex/profile.html', context)

from django.shortcuts import render
from django.contrib.auth.forms import UserCreationForm
from django.contrib import messages
from d06.settings import usernames
from random import choice
from django.contrib.auth import login, authenticate
from django.contrib.auth.forms import UserCreationForm
from django.shortcuts import redirect
from .forms import TipForm
from .models import Tip


def homepage(request):

    data = Tip.objects.all()
    context = {"tip": data}
    username = request.COOKIES.get('42-cookie')

    if request.method == 'POST':
        form = TipForm(request.POST)
        if form.is_valid():
            obj = Tip()
            obj.content = form.cleaned_data.get('content')
            obj.author = form.cleaned_data.get('author')
            obj.date = form.cleaned_data.get('date')
            obj.save()
            return redirect('http://127.0.0.1:8000')
    else:
        form = TipForm()
        if username:
            context.update({'username': username})
            context.update({'form': form})
            return render(request, "user.html", context)
        else:
            data = choice(usernames)
            context.update({'username': data})
            context.update({'form': form})
            html = render(request, "user.html", context)
            html.set_cookie('42-cookie', data, max_age = 42)
            return html


def registration(request):

    if request.user.is_authenticated:
        return redirect('http://127.0.0.1:8000')

    if request.method == 'POST':
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get('username')
            raw_password = form.cleaned_data.get('password1')
            user = authenticate(username=username, password=raw_password)
            login(request, user)
            return redirect('http://127.0.0.1:8000')
    else:
        form = UserCreationForm()
        return render(request, 'registration.html', {'form': form})


def test(request):

    if request.method == 'POST':
        form = TipForm(request.POST)
        if form.is_valid():
            obj = Tip()
            obj.content = form.cleaned_data.get('content')
            obj.author = form.cleaned_data.get('author')
            obj.date = form.cleaned_data.get('date')
            obj.save()
            return redirect('http://127.0.0.1:8000')
    else:
        form = TipForm()
        return render(request, 'test.html', {'form': form})
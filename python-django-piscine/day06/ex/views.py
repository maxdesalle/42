from django.shortcuts import render
from django.contrib.auth.forms import UserCreationForm
from django.contrib import messages
from django.forms import ValidationError
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
                context.update({'error': 'An error occurred, please try again with correct values'})
                return render(request, "user.html", context)
            else:
                data = choice(usernames)
                context.update({'username': data})
                context.update({'form': form})
                context.update({'error': 'An error occurred, please try again with correct values'})
                html = render(request, "user.html", context)
                html.set_cookie('42-cookie', data, max_age = 42)
                return html
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
            return redirect('http://127.0.0.1:8000/registration')
    else:
        form = UserCreationForm()
        return render(request, 'registration.html', {'form': form})

def objdelete(request, id):
    Tip.objects.filter(id=id).delete()
    return redirect('http://127.0.0.1:8000')

def upvote(request, id):
    obj = Tip.objects.get(id=id)
    if (obj.upstats > 0):
        obj.upstats -= 1
    else:
        obj.upstats += 1
    if (obj.downstats < 0):
        obj.downstats += 1
    obj.save()
    return redirect('http://127.0.0.1:8000')

def downvote(request, id):
    obj = Tip.objects.get(id=id)
    if (obj.downstats < 0):
        obj.downstats += 1
    else:
        obj.downstats -= 1
    if (obj.upstats > 0):
        obj.upstats -= 1
    obj.save()
    return redirect('http://127.0.0.1:8000')

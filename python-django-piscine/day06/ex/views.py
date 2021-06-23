from django.shortcuts import render
from django.contrib.auth.forms import UserCreationForm
from django.contrib import messages
from d06.settings import usernames
from random import choice
from django.contrib.auth import login, authenticate
from django.contrib.auth.forms import UserCreationForm
from django.shortcuts import redirect


def homepage(request):

    username = request.COOKIES.get('42-cookie')

    if username:
        context = {'username': username}
        return render(request, "user.html", context)

    else:
        data = choice(usernames)
        context = {'username': data}
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

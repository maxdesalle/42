from django.shortcuts import render
from d06.settings import usernames
from random import choice

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

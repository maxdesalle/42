from django.http import HttpResponse
from django.shortcuts import render


def django_intro(request):
    return render(request, "django_intro.html", {})

def display_intro(request):
    return render(request, "display_intro.html", {})

def templates_intro(request):
    return render(request, "templates_intro.html", {})

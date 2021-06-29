from django.shortcuts import render, redirect
from django.conf import settings
from django.contrib import messages
import random


def index(request):
    return redirect('forum')

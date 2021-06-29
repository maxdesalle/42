from django.shortcuts import render, redirect
from django.contrib.auth.forms import UserCreationForm
from django.contrib import messages
from django.contrib.auth import authenticate, login
#from .forms import registerForm

def register(request):
    print(request.user.is_authenticated)
    if  request.user.is_authenticated:
        return redirect('index')
    if  request.method == 'POST':
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            #username = form.cleaned_data.get('username')
            new_user = authenticate(username=form.cleaned_data['username'],
                                    password=form.cleaned_data['password1'])
            login(request, new_user)
            messages.success(request, f'Your user has been created, you are now logged in')
            return redirect('/forum')
    else:
        form = UserCreationForm()
    return render(request, 'ex/register.html', {'form':form} )

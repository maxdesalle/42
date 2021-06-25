from django.shortcuts import render, redirect
from .models import Flash
from .forms import FlashForm


def homepage(request):

    data = Flash.objects.all()
    context = {"flash": data}
    
    if request.method == 'POST':
        form = FlashForm(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            return redirect('/')
        else:
            form = FlashForm()
            context.update({'form': form})
            context.update({'error': 'An error occurred, please try again with a different image'})
            return render(request, "homepage.html", context)
    else:
        form = FlashForm()
        context.update({'form': form})
        return render(request, "homepage.html", context)

    return render(request, 'homepage.html')


def objdelete(request, id):
    Flash.objects.filter(id=id).delete()
    return redirect('/')

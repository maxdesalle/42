from django.shortcuts import render, redirect
from django.conf import settings
from django.contrib import messages
from forum.models import Post, Upvote
from forum.forms import PostForm
  
def create_post(request):
    if request.method == 'POST':
        form = PostForm(request.POST)
        if form.is_valid():
            content = form.cleaned_data['content']
            title = form.cleaned_data['title']
            post = Post(content = content,title = title, author = request.user)
            post.save()
            messages.success(request, f'New post created')
            return redirect('forum')
    else:
        form = PostForm()
    context = {
        'PostForm' : PostForm,
    }
    return render(request, 'forum/post_creation.html', context)

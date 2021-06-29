from django.shortcuts import render, redirect, get_object_or_404
from django.conf import settings
from django.contrib import messages
from forum.models import Post, Comment
from forum.forms import CommentForm
import random

def post_details(request, pk):
    le_post = get_object_or_404(Post, id = pk)
    if request.method == 'POST':
        comment_form = CommentForm(data=request.POST)
        if comment_form.is_valid():
            parent_obj = None
            try:
                parent_id = int(request.POST.get('parent_id'))
            except:
                parent_id = None
            if parent_id:
                parent_obj = Comment.objects.get(id=parent_id)
                if parent_obj:
                    replay_comment = comment_form.save(commit=False)
                    replay_comment.parent = parent_obj
            new_comment = comment_form.save(commit=False)
            new_comment.name = request.user
            new_comment.post = le_post
            new_comment.save()
            return redirect('post_details', pk = le_post.id)
    le_post = get_object_or_404(Post, id = pk)
    comments = Comment.objects.all()
    post_comments = []
    for comment in comments:
        if comment.post == le_post:
            post_comments.append(comment)
    comment_form = CommentForm()
    return render(request, 'forum/post_details.html',{'post': le_post, 'comments': post_comments,'comment_form': comment_form})
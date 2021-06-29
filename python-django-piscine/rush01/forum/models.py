from django.db import models
from django.contrib.auth.models import User


class Post(models.Model):

    id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=100)
    content = models.TextField(max_length=5000)
    author = models.ForeignKey(User, on_delete=models.CASCADE)
    date = models.DateTimeField(auto_now_add=True, null = False)
    upusers = models.ManyToManyField(User, related_name="upusers")
    downusers = models.ManyToManyField(User, related_name="downusers")
    upstats = models.SmallIntegerField(default=0)
    downstats = models.SmallIntegerField(default=0)

    def __str__(self):
        return str(self.title)
    
    def l_upusers(self):
        string = ""
        for i in self.upusers.all():
            string += "{} ".format(i)
        return (string)

    def l_downusers(self):
        string = ""
        for i in self.downusers.all():
            string += "{} ".format(i)
        return (string)


class Upvote(models.Model):

    vote = models.BooleanField(default=False)
    user = models.ForeignKey(User, related_name='upvote', on_delete=models.CASCADE)
    post = models.ForeignKey(Post, related_name='upvote', on_delete=models.CASCADE)
    
    class Meta:
        unique_together = (('user', 'post'),)


class Downvote(models.Model):

    vote = models.BooleanField(default=False)
    user = models.ForeignKey(User, related_name='downvote', on_delete=models.CASCADE)
    post = models.ForeignKey(Post, related_name='downvote', on_delete=models.CASCADE)
    
    class Meta:
        unique_together = (('user', 'post'),)


class Comment(models.Model):
    post = models.ForeignKey(Post, related_name='comments', on_delete=models.CASCADE)
    name = models.CharField(max_length=80)
    content = models.TextField()
    created = models.DateTimeField(auto_now_add=True)
    parent = models.ForeignKey('self', null=True, blank=True, related_name='replies', on_delete=models.CASCADE)

    class Meta:
        # sort comments in chronological order by default
        ordering = ('created',)

    def __str__(self):
        return 'Comment by {}'.format(self.name)

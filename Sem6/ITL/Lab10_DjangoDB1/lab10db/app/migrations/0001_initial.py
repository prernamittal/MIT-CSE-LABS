# Generated by Django 4.2.11 on 2024-03-14 05:18

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='BlogPost',
            fields=[
                ('title', models.CharField(max_length=150)),
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('body', models.TextField()),
                ('timestamp', models.DateTimeField()),
            ],
            options={
                'ordering': ('-timestamp',),
            },
        ),
    ]

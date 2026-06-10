What is the difference between `git merge` and `git rebase`? #git #version-control

---

- **`git merge`**
  - Creates a **new commit** that combines the histories of two branches.
  - Preserves the **full branch history** (including merge commits).
- **`git rebase`**
  - **Replays** your branch's commits onto a **base commit** (`git rebase main`, `git rebase abc123`, a tag, etc.).
  - A branch name is just shorthand for "whatever commit that branch points to" - usually the tip, but any commit works.
  - Produces a **linear history** with no merge commits.

%%%MOCHI_CARD%%%
What is the difference between linear and merged commit history? #git #version-control

---

- **Linear history**
  - Commits form a **straight line** - each commit has **one parent** (except the root).
  - Typical after **`git rebase`**, **squash merge**, or working on a single branch with no parallel work.
  - `git log` reads like a simple timeline: oldest → newest.
- **Merged history**
  - **Merge commits** join two lines of development - they have **two parents**.
  - Typical after **`git merge`** when branches diverged and come back together.
  - `git log --graph` shows **Y-shaped** branch/merge points.

```text
  Linear (rebase / squash)

  A --- B --- C --- D --- E
                    ^
                 one parent chain


  Merged (git merge)

  A --- B --- C ----------- M
               \           /
                D --- E ---
                            ^
                      merge commit (2 parents)
```

- **Trade-offs**
  - **Linear**: easier to read, bisect, and follow `git blame`; rebasing **rewrites** commit hashes (avoid on shared branches).
  - **Merged**: preserves **when and where** branches diverged and reunited; no rewrite of existing commits.

%%%MOCHI_CARD%%%
What is `git stash`, and when would you use it? #git #version-control

---

- **What it does**
  - Temporarily saves **uncommitted changes** (both staged and unstaged).
  - Lets you switch branches or pull without committing incomplete work.
- **Restore**
  - `git stash pop` - apply and remove the latest stash.
  - `git stash apply` - apply but keep the stash entry.

%%%MOCHI_CARD%%%
What is the difference between `git reset` and `git revert`? #git #version-control

---

- **`git reset`**
  - Moves **HEAD** (and optionally the branch pointer) to a previous commit.
  - Effectively **erases** commits from the current branch history.
  - Modes: `--soft` (keep staged), `--mixed` (default), `--hard` (discard working tree).
- **`git revert`**
  - Creates a **new commit** that undoes a specific earlier commit.
  - **Preserves history** - safer on shared branches.

%%%MOCHI_CARD%%%
What is the staging area (index) in Git? #git #version-control

---

The **staging area** is an intermediate zone between your **working directory** and the **repository**.

- **`git add`**
  - Places selected changes into the index.
- **`git commit`**
  - Snapshots only what is staged, so you can craft commits with partial file changes.

%%%MOCHI_CARD%%%
What is a detached HEAD state? #git #version-control

---

A **detached HEAD** occurs when you check out a **specific commit hash** instead of a branch name.

- **Risk**
  - New commits are not on any branch; they can be **lost** if you switch away without saving them.
- **Use case**
  - Inspect or test an old commit - not ideal for ongoing work unless you create a branch from that point.

%%%MOCHI_CARD%%%
What is the difference between `git pull` and `git fetch`? #git #version-control

---

- **`git fetch`**
  - Downloads remote changes into **remote-tracking branches**.
  - Does **not** merge into your current local branch.
- **`git pull`**
  - **`fetch` + integrate** (merge or rebase, depending on config).
  - Updates your **current local branch** with remote changes.

%%%MOCHI_CARD%%%
What is a merge conflict, and how do you resolve it? #git #version-control

---

A **merge conflict** happens when Git cannot automatically reconcile edits to the **same lines** in the **same file** on different branches.

1. Open conflicted files; look for markers: `<<<<<<<`, `=======`, `>>>>>>>`.
2. Edit to keep the correct combined content.
3. `git add` the resolved file(s).
4. `git commit` to complete the merge.

%%%MOCHI_CARD%%%
What is the difference between `git clone` and a fork? #git #version-control

---

- **`git clone`**
  - A Git **command** that creates a **local copy** of a remote repository.
- **Fork**
  - A **GitHub/GitLab** feature that copies someone else's repo **under your account** on the platform.
  - You typically **clone your fork** locally to work on it.

%%%MOCHI_CARD%%%
What does `git cherry-pick` do? #git #version-control

---

`git cherry-pick <commit-hash>` applies the changes from **one specific commit** onto your **current branch**.

- **Use case**
  - Bring a single fix or feature from another branch **without merging** the whole branch.

%%%MOCHI_CARD%%%
What is the purpose of `.gitignore`? #git #version-control

---

The **`.gitignore`** file lists paths Git should **never track**.

- **Examples**
  - Build artifacts, logs, `.env`, `node_modules`, IDE caches.
- **Effect**
  - Prevents unwanted files from being staged or committed.

%%%MOCHI_CARD%%%
What is `git bisect`, and how does it work? #git #version-control

---

**`git bisect`** uses **binary search** to find the commit that introduced a bug.

1. `git bisect start`
2. `git bisect good <hash>` - last known good commit.
3. `git bisect bad <hash>` - first known bad commit.
4. Git checks out the **midpoint**; you test and mark `good` or `bad`.
5. Repeat until the offending commit is identified.

%%%MOCHI_CARD%%%
What are the three main areas of a Git project? #git #version-control

---

| Area                     | Description                                              |
| :----------------------: | :------------------------------------------------------: |
| **Working directory**    | Local files on your filesystem that you edit             |
| **Staging area (index)** | Prepared snapshot of what goes into the **next** commit  |
| **Repository (`.git`)**  | Committed history Git stores permanently                 |

```text
  edit files  -->  git add  -->  git commit
  working tree       index         repository (.git)
```

- **Working directory**
  - The normal project folder you see in your editor.
  - Saving a file updates the working tree only - Git does **not** auto-commit.
  - `git status` lists **unstaged** changes here ("Changes not staged for commit").
- **Staging area (index)**
  - **Same thing, two names** - "staging area" in docs, **index** in Git internals (`git write-tree` reads the index).
  - Not a second copy of your whole project - a **checklist** of which file versions belong in the **next** snapshot.
  - `git add <file>` copies the **current** version of that file into the index.
  - `git status` shows staged items as "Changes to be committed."
  - **Partial commits**: stage file A but not file B, or use `git add -p` to stage only some hunks in one file.
  - **Why it exists**: split messy working-tree edits into clean, logical commits before they become permanent history.
- **Repository (`.git`)**
  - Hidden `.git` directory - objects, branches, tags, reflog.
  - `git commit` takes whatever is in the index and writes a **permanent** snapshot (a commit) into the repo.
  - Committed history is what you push, share, and revert to.

%%%MOCHI_CARD%%%
What is the difference between a local branch and a remote-tracking branch? #git #version-control

---

- **Local branch**
  - Lives on your machine; its tip moves as **you** commit.
- **Remote-tracking branch** (e.g. `origin/main`)
  - A **local reference** to the state of a branch on the remote.
  - Updates only when you **`fetch`** or **`pull`**.

%%%MOCHI_CARD%%%
What does `git reflog` do? #git #version-control

---

**`git reflog`** records every change to the tip of branches and **HEAD** - including commits that look "lost" after a **rebase** or **reset**.

- **Recovery**
  - Find the commit hash in the reflog, then `git checkout` or `git reset` to restore it.

%%%MOCHI_CARD%%%
How do you squash commits? #git #version-control

---

Combine multiple commits into one with **interactive rebase**:

```bash
git rebase -i HEAD~n   # n = number of commits to combine
```

- In the editor, change **`pick`** to **`squash`** (or **`s`**) for commits to fold into the one above.
- Save and close, then edit the combined commit message.
